#include "LayerManager/LayerManagerComponent.h"
#include "LayerManager/PanelDefinition.h"
#include "LayerManager/WidgetSpawnerSubsystem.h"
#include "Blueprint/UserWidget.h"
#include "Engine/World.h"

ULayerManagerComponent::ULayerManagerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void ULayerManagerComponent::BeginPlay()
{
	Super::BeginPlay();

	if (PanelDefinition->PanelOverrides.Num() == 0) return;

	BuildSortedWidgetList();
	SpawnHighestPriorityWidget();
}

void ULayerManagerComponent::BuildSortedWidgetList()
{
	if (!PanelDefinition) return;

	for (const auto& LayerPair : PanelDefinition->PanelOverrides)
	{
		const int32 LayerID = LayerPair.Key;
		const FLayerUI& LayerUI = LayerPair.Value;

		SortedLayerEntries.Add({ LayerID, LayerUI.NamePanel, LayerUI.LayerWidget });
	}

	SortLayers(SortedLayerEntries);
}

void ULayerManagerComponent::SpawnHighestPriorityWidget()
{
	for (const FEntryToCreate& Entry : SortedLayerEntries)
	{
		if (Entry.WidgetSoft == nullptr) continue;
		SetNewWidget(Entry);
		return;
	}
}

void ULayerManagerComponent::SetNewWidget(FEntryToCreate LocalEntry)
{
	if (UWorld* World = GetWorld()) 
	{
		UWidgetSpawnerSubsystem* Spawner = World->GetGameInstance()->GetSubsystem<UWidgetSpawnerSubsystem>();
		if (Spawner)
		{
			UUserWidget* Widget = Spawner->SpawnWidget(LocalEntry.WidgetSoft);
			Spawner->AddToViewport(Widget, LocalEntry.WidgetID);
		}
	}
}

void ULayerManagerComponent::SortLayers(TArray<FEntryToCreate>& TempArray)
{
	TempArray.Sort([](const FEntryToCreate& A, const FEntryToCreate& B)
	{
		return A.WidgetID > B.WidgetID;
	});
}