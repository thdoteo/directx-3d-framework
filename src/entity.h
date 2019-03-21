#pragma once

#include "vector.h"
#include "simple_vertex.h"
#include "constant_buffer.h"


class Entity
{
protected:
	VEC3 position;
public:
	Entity() {}
	virtual void Render(ID3D11DeviceContext*, ConstantBuffer&, ID3D11Buffer*, UINT*, UINT*) = 0;
	virtual void Register(ID3D11Device*, D3D11_BUFFER_DESC&, D3D11_SUBRESOURCE_DATA&) = 0;
};