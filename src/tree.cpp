#include "tree.h"



Tree::Tree(double x, double y)
{
	n_vertices = 6;
	vertices = new SimpleVertex[n_vertices];

	vertices[0].Pos = XMFLOAT3(x - 0.05f, y + 0.35f, 0);
	vertices[1].Pos = XMFLOAT3(x + 0.05f, y + 0.35f, 0);
	vertices[2].Pos = XMFLOAT3(x - 0.05f, y - 0.5f, 0);
	vertices[3].Pos = XMFLOAT3(x + 0.05f, y + 0.35f, 0);
	vertices[4].Pos = XMFLOAT3(x + 0.05f, y - 0.5f, 0);
	vertices[5].Pos = XMFLOAT3(x - 0.05f, y - 0.5f, 0);

	leave0 = new S2DCircle(x, y - 0.15, 0.2, 360, new FloatColor(0.0156f, 0.5f, 0.0f));
	leave1 = new S2DCircle(x, y, 0.2, 360, new FloatColor(0.0156f, 0.6f, 0.0f));
	leave2 = new S2DCircle(x, y + 0.15, 0.2, 360, new FloatColor(0.0156f, 0.7f, 0.0f));
	leave3 = new S2DCircle(x, y + 0.30, 0.2, 360, new FloatColor(0.0156f, 0.75f, 0.0f));
	leave4 = new S2DCircle(x, y + 0.45, 0.2, 360, new FloatColor(0.0156f, 0.8f, 0.0f));
}

void Tree::Register(ID3D11Device* g_pd3dDevice, D3D11_BUFFER_DESC& bd, D3D11_SUBRESOURCE_DATA& InitData)
{
	ZeroMemory(&bd, sizeof(bd));
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(SimpleVertex) * n_vertices;
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = 0;
	ZeroMemory(&InitData, sizeof(InitData));
	InitData.pSysMem = vertices;
	g_pd3dDevice->CreateBuffer(&bd, &InitData, &g_pVertexBuffer);

	leave0->Register(g_pd3dDevice, bd, InitData);
	leave1->Register(g_pd3dDevice, bd, InitData);
	leave2->Register(g_pd3dDevice, bd, InitData);
	leave3->Register(g_pd3dDevice, bd, InitData);
	leave4->Register(g_pd3dDevice, bd, InitData);
}

void Tree::Render(ID3D11DeviceContext* g_pImmediateContext, ConstantBuffer& VsConstData, ID3D11Buffer* g_pConstantBuffer, UINT* stride, UINT* offset)
{
	g_pImmediateContext->UpdateSubresource(g_pConstantBuffer, 0, 0, &VsConstData, 0, 0);
	g_pImmediateContext->IASetVertexBuffers(0, 1, &g_pVertexBuffer, stride, offset);
	g_pImmediateContext->Draw(n_vertices, 0);
	leave0->Render(g_pImmediateContext, VsConstData, g_pConstantBuffer, stride, offset);
	leave1->Render(g_pImmediateContext, VsConstData, g_pConstantBuffer, stride, offset);
	leave2->Render(g_pImmediateContext, VsConstData, g_pConstantBuffer, stride, offset);
	leave3->Render(g_pImmediateContext, VsConstData, g_pConstantBuffer, stride, offset);
}
