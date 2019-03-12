#pragma once



struct ConstantBuffer
{
	XMMATRIX mWorld;
	XMMATRIX mView;
	XMMATRIX mProjection;

	float fColorR;
	float fColorG;
	float fColorB;
};