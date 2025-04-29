#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "WidgetSpawnerSubsystem.generated.h"

UCLASS()
class UILAYERSYSTEM_API UWidgetSpawnerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	UUserWidget* SpawnWidget(TSoftClassPtr<UUserWidget> WidgetClass);

	void AddToViewport(UUserWidget* Widget, int32 ZOrder = 0);

};
