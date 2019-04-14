#pragma once
#include "fcolor.h"
#include "entity.h"



class Object : public Entity
{
protected:
	int n_vertices;
	FloatColor* color;
	SimpleVertex *vertices;
	ID3D11Buffer* g_pVertexBuffer;

public:
	Object() {}
	virtual ~Object() {}
	virtual void Register(ID3D11Device*, D3D11_BUFFER_DESC&, D3D11_SUBRESOURCE_DATA&, ID3D11DeviceContext*);
	virtual void Render(XMMATRIX&, float);
};