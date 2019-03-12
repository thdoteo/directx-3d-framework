#pragma once
#include "fcolor.h"
#include "entity.h"



class Shape : public Entity
{
protected:
	int n_vertices;
	FloatColor* color;
	SimpleVertex *vertices;
	ID3D11Buffer* g_pVertexBuffer;

public:
	Shape() {}
	virtual ~Shape() {}
	virtual void Register(ID3D11Device*, D3D11_BUFFER_DESC&, D3D11_SUBRESOURCE_DATA&);
	virtual void Render(ID3D11DeviceContext*, ConstantBuffer&, ID3D11Buffer*, UINT*, UINT*);
};