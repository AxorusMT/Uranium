#include "Shader.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

enum ShaderType
{
    INVALID = -1,
    VERTEX = 0,
    FRAGMENT = 1
};

typedef struct
{
    /* data */
} ShaderProgramSource;



namespace Uranium
{
    void Shader::parseShader(const std::string& filepath)
    {
        std::ifstream stream(filepath);
        // the current line we are on
        std::string line;
        std::stringstream strstrm[2];

        ShaderType currentType = ShaderType::INVALID;

        while (getline(stream, line))
        {
            // if the line has '#shader_type'
            if (line.find("#shader_type") != std::string::npos)
            {
                if (line.find("vertex") !=  std::string::npos)
                {

                }

                else if (line.find("fragment") != std::string::npos)
                {
                
                }            
            }

            else
            {
                strstrm[(int)currentType] << line << "\n";
            }
        }
    }
}