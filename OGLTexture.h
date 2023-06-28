/*
Part of Newcastle University's Game Engineering source code.

Use as you see fit!

Comments and queries to: richard-gordon.davison AT ncl.ac.uk
https://research.ncl.ac.uk/game/
*/
#pragma once
#include "Texture.h"
#include "glad\gl.h"

namespace NCL {
	namespace Rendering {
		class OGLTexture : public Texture
		{
		public:
			//friend class OGLRenderer;
			 OGLTexture();
			 OGLTexture(GLuint texToOwn);
			~OGLTexture();

			static Texture* RGBATextureFromData(char* data, int width, int height, int channels);

			static Texture* RGBATextureFromFilename(const std::string&name);

			static Texture* LoadCubemap(
				const std::string& xPosFile,
				const std::string& xNegFile,
				const std::string& yPosFile,
				const std::string& yNegFile,
				const std::string& zPosFile,
				const std::string& zNegFile);


			GLuint GetObjectID() const	{
				return texID;
			}
		protected:						
			GLuint texID;
		};
	}
}

