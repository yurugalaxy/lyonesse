//
// Created by kae on 18/08/24.
//

#pragma once

#include "base.hpp"

namespace Lyonesse
{
  class Shader
  {
  public:
    Shader(const char* vertPath, const char* fragPath);
    ~Shader();
    void Use();
    void UploadUniformBool(const std::string& name, bool value) const;
    void UploadUniformInt(const std::string& name, int value) const;
    void UploadUniformFloat(const std::string& name, float value) const;
    void UploadUniformFloat2(const std::string& name, const glm::vec2& value) const;
    void UploadUniformFloat3(const std::string& name, const glm::vec3& value) const;
    void UploadUniformFloat4(const std::string& name, const glm::vec4& value) const;
    void UploadUniformMat3(const std::string& name, const glm::mat3& value) const;
    void UploadUniformMat4(const std::string& name, const glm::mat4& value) const;
    U32 ID() {return m_shaderID;}

  private:
    U32 m_shaderID {};
  };
}
