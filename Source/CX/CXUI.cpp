// Copyright Epic Games, Inc. All Rights Reserved.


#include "CXUI.h"
#include "Components/TextBlock.h"          // 추가
#include "PlayerState/CXPlayerState.h"     // 추가

// 추가
void UCXUI::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if (PlayerStateInfo == nullptr)
	{
		return;
	}

	// 클라이언트는 시작 직후 PlayerState가 아직 없을 수 있어서 매 틱 확인
	if (ACXPlayerState* PS = Cast<ACXPlayerState>(GetOwningPlayerState()))
	{
		PlayerStateInfo->SetText(FText::FromString(PS->GetPlayerStateInfo()));
	}
}

void UCXUI::OnNewChatMessage(const FString& InSender, const FString& InMessage)
{
	UI_Chat->OnNewChatMessage(InSender, InMessage);
}

void UCXUI::UpdateSpeed(float NewSpeed)
{
	// format the speed to KPH or MPH
	float FormattedSpeed = FMath::Abs(NewSpeed) * (bIsMPH ? 0.022f : 0.036f);

	// call the Blueprint handler
	OnSpeedUpdate(FormattedSpeed);
}

void UCXUI::UpdateGear(int32 NewGear)
{
	// call the Blueprint handler
	OnGearUpdate(NewGear);
}