/*
Part of Newcastle University's Game Engineering source code.

Use as you see fit!

Comments and queries to: richard-gordon.davison AT ncl.ac.uk
https://research.ncl.ac.uk/game/
*/
#pragma once
#include "Shader.h"
#include "glad\gl.h"

namespace NCL {
	namespace Rendering {
		class OGLShader : public Shader
		{
		public:
			friend class OGLRenderer;
			OGLShader(const std::string& vertex, const std::string& fragment, const std::string& geometry = "", const std::string& domain = "", const std::string& hull = "");
			~OGLShader();

			void ReloadShader() override;

			bool LoadSuccess() const {
				return programValid == GL_TRUE;
			}

			int GetProgramID() const {
				return programID;
			}	
			
			static void	PrintCompileLog(GLuint object);
			static void	PrintLinkLog(GLuint program);

			static bool Preprocessor(std::string& shaderFile);

		protected:
			void	DeleteIDs();

			GLuint	programID;
			GLuint	shaderIDs[(int)ShaderStages::MAXSIZE];
			int		shaderValid[(int)ShaderStages::MAXSIZE];
			int		programValid;
		};
	}
}