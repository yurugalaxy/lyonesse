#include "shader.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

namespace Lyonesse
{
  Shader::Shader(const char* vertPath, const char* fragPath)
  {
    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;

    vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try
    {
      vShaderFile.open(vertPath);
      fShaderFile.open(fragPath);
      std::stringstream vShaderStream, fShaderStream;

      vShaderStream << vShaderFile.rdbuf();
      fShaderStream << fShaderFile.rdbuf();

      vShaderFile.close();
      fShaderFile.close();

      vertexCode = vShaderStream.str();
      fragmentCode = fShaderStream.str();
    } catch (std::ifstream::failure& e)
    {
      std::cout << "Shader file not read.\n";
    }
    const char* vShaderCode = vertexCode.c_str();
    const char* fShaderCode = fragmentCode.c_str();

    U16 vertex, fragment;
    int success;
    char infoLog[512];

    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, nullptr);
    glCompileShader(vertex);

    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    if (!success)
    {
      glGetShaderInfoLog(vertex, 512, nullptr, infoLog);
      std::cout << "Vertex shader compilation failed." << infoLog << '\n';
    }

    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, nullptr);
    glCompileShader(fragment);

    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
    if (!success)
    {
      glGetShaderInfoLog(fragment, 512, nullptr, infoLog);
      std::cout << "Fragment shader compilation failed." << infoLog << '\n';
    }

    m_shaderID = glCreateProgram();
    glAttachShader(m_shaderID, vertex);
    glAttachShader(m_shaderID, fragment);
    glLinkProgram(m_shaderID);

    glGetProgramiv(m_shaderID, GL_LINK_STATUS, &success);
    if (!success)
    {
      glGetProgramInfoLog(m_shaderID, 512, nullptr, infoLog);
      std::cout << "Shader program linking failed." << infoLog << '\n';
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);

    std::cout << "Created shader " << m_shaderID << ".\n";
  }

  Shader::~Shader()
  {
    glDeleteProgram(m_shaderID);
    std::cout << "Destroyed shader " << m_shaderID << ".\n";
  }

  void Shader::Use()
  {
    glUseProgram(m_shaderID);
  }
   void Shader::UploadUniformBool(const std::string& name, const bool value) const
  {
    const GLint location = glGetUniformLocation(m_shaderID, name.c_str());
    glUniform1i(location, value);
  }

  void Shader::UploadUniformInt(const std::string& name, const int value) const
  {
    const GLint location = glGetUniformLocation(m_shaderID, name.c_str());
    glUniform1i(location, value);
  }

  void Shader::UploadUniformFloat(const std::string& name, const float value) const
  {
    const GLint location = glGetUniformLocation(m_shaderID, name.c_str());
    glUniform1f(location, value);
  }

  void Shader::UploadUniformFloat2(const std::string& name, const glm::vec2& value) const
  {
    const GLint location = glGetUniformLocation(m_shaderID, name.c_str());
    glUniform2f(location, value.x, value.y);
  }

  void Shader::UploadUniformFloat3(const std::string& name, const  glm::vec3& value) const
  {
    const GLint location = glGetUniformLocation(m_shaderID, name.c_str());
    glUniform3f(location, value.x, value.y, value.z);
  }

  void Shader::UploadUniformFloat4(const std::string& name, const glm::vec4& value) const
  {
    const GLint location = glGetUniformLocation(m_shaderID, name.c_str());
    glUniform4f(location, value.x, value.y, value.z, value.w);
  }

  void Shader::UploadUniformMat3(const std::string& name, const glm::mat3& value) const
  {
    const GLint location = glGetUniformLocation(m_shaderID, name.c_str());
    glUniformMatrix3fv(location, 1, GL_FALSE, &value[0][0]);
  }

  void Shader::UploadUniformMat4(const std::string& name, const glm::mat4& value) const
  {
    const GLint location = glGetUniformLocation(m_shaderID, name.c_str());
    glUniformMatrix4fv(location, 1, GL_FALSE, &value[0][0] );
  }
}
