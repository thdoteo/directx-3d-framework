#pragma once
#include "shape.h"
#include "cycloid.h"



class Tree :
	public Shape
{
private:
	S2DCircle *leave0, *leave1, *leave2, *leave3, *leave4;
public:
	Tree(double, double);
	void Register(ID3D11Device*, D3D11_BUFFER_DESC&, D3D11_SUBRESOURCE_DATA&);
	void Render(ID3D11DeviceContext*, ConstantBuffer&, ID3D11Buffer*, UINT*, UINT*);
};