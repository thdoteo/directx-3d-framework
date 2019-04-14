#include "object.h"



void Object::Register(ID3D11Device* g_pd3dDevice, D3D11_BUFFER_DESC& bd, D3D11_SUBRESOURCE_DATA& InitData, ID3D11DeviceContext* g_pImmediateContext)
{
	ZeroMemory(&bd, sizeof(bd));
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(SimpleVertex) * n_vertices;
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = 0;
	ZeroMemory(&InitData, sizeof(InitData));
	InitData.pSysMem = vertices;

	UINT stride = sizeof(SimpleVertex);
	UINT offset = 0;
	g_pd3dDevice->CreateBuffer(&bd, &InitData, &g_pVertexBuffer);
	g_pImmediateContext->IASetVertexBuffers(0, 1, &g_pVertexBuffer, &stride, &offset);
}

void Object::Render(XMMATRIX& g_World, float t) {
	// Test animation
	g_World = XMMatrixRotationY(-t);
	g_World *= XMMatrixTranslation(position.x, position.y, position.z);
}