#include "cuboid.h"



Cuboid::Cuboid(float x, float y, float z, FloatColor* _color) {
	position.x = x;
	position.y = y;
	position.z = z;
	color = _color;

	n_vertices = 8;
	vertices = new SimpleVertex[n_vertices];
	vertices[0].Pos = XMFLOAT3(-1.0f, 1.0f, -1.0f);
	vertices[1].Pos = XMFLOAT3(1.0f, 1.0f, -1.0f);
	vertices[2].Pos = XMFLOAT3(1.0f, 1.0f, 1.0f);
	vertices[3].Pos = XMFLOAT3(-1.0f, 1.0f, 1.0f);
	vertices[4].Pos = XMFLOAT3(-1.0f, -1.0f, -1.0f);
	vertices[5].Pos = XMFLOAT3(1.0f, -1.0f, -1.0f);
	vertices[6].Pos = XMFLOAT3(1.0f, -1.0f, 1.0f);
	vertices[7].Pos = XMFLOAT3(-1.0f, -1.0f, 1.0f);

	for (int i = 0; i < 8; i++)
	{
		vertices[i].Color = XMFLOAT4(color->r, color->g, color->b, 1.0f);
	}
}