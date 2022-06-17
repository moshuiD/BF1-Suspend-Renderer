#include "pch.h"
#include "SetRenderer.h"
void SetRenderer::SetState(State state)
{
	switch (state)
	{
	case SetRenderer::Suspend:
		Write(0x14347D4E8, 1);
		break;
	case SetRenderer::Unsuspend:
		Write(0x14347D4E8, 0);
		break;
	}
	
}