/*
Part of Newcastle University's Game Engineering source code.

Use as you see fit!

Comments and queries to: richard-gordon.davison AT ncl.ac.uk
https://research.ncl.ac.uk/game/
*/
#pragma once
#include "glad\gl.h"

namespace NCL {
	class OGLComputeShader	{
	public:
		OGLComputeShader(const std::string& s);
		~OGLComputeShader();

		GLuint GetProgramID() const {
			return programID;
		}

		void Bind() const;
		void Unbind();

		//how many thread groups should be launched?
		//number of threads within a group is determined shader side
		void Execute(unsigned int x, unsigned int y = 1, unsigned int z = 1) const;

		Maths::Vector3i GetThreadGroupSize() const {
			return threadsInGroup;
		}

	protected:
		GLuint		shaderID;
		GLuint		programID;
		int			programValid;
		Maths::Vector3i	threadsInGroup;
	};
}

