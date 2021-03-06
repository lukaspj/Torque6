//-----------------------------------------------------------------------------
// Copyright (c) 2015 Andrew Mac
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
//-----------------------------------------------------------------------------

#include <plugins/plugins_shared.h>
#include "ParticlesPlugin.h"
#include <sim/simObject.h>
#include <rendering/rendering.h>
#include <graphics/core.h>
#include <bx/fpumath.h>
#include "particleEmitter.h"

Graphics::PosUVColorVertex particleVerts[4] =
{
	{-1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 0xffffffff },
	{-1.0f, 1.0f,  1.0f, 1.0f, 1.0f, 0xffffffff },
	{ 1.0f, 1.0f, -1.0f, 0.0f, 0.0f, 0xffffffff },
	{ 1.0f, 1.0f,  1.0f, 0.0f, 1.0f, 0xffffffff }
};

U16 particleIndices[6] = {0, 2, 1, 1, 2, 3};

void create()
{
   // Load Shared index/vertex buffer.
   const bgfx::Memory* mem;

   mem = Torque::bgfx.makeRef(&particleVerts[0], sizeof(Graphics::PosUVColorVertex) * 4, NULL, NULL);
   Scene::ParticleEmitter::vertexBuffer = Torque::bgfx.createVertexBuffer(mem, *Torque::Graphics.PosUVColorVertex, BGFX_BUFFER_NONE);

	mem = Torque::bgfx.makeRef(&particleIndices[0], sizeof(uint16_t) * 6, NULL, NULL);
	Scene::ParticleEmitter::indexBuffer = Torque::bgfx.createIndexBuffer(mem, BGFX_BUFFER_NONE);
}

void destroy()
{
   if ( Scene::ParticleEmitter::vertexBuffer.idx != bgfx::invalidHandle )
      Torque::bgfx.destroyVertexBuffer(Scene::ParticleEmitter::vertexBuffer);

   if ( Scene::ParticleEmitter::indexBuffer.idx != bgfx::invalidHandle )
      Torque::bgfx.destroyIndexBuffer(Scene::ParticleEmitter::indexBuffer);
}