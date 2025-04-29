#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LayerManagerComponent.generated.h"

USTRUCT()
struct FEntryToCreate
{
	GENERATED_BODY()

	int32 WidgetID;
	FName WidgetName;
	TSoftClassPtr<UUserWidget> WidgetSoft;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UILAYERSYSTEM_API ULayerManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	ULayerManagerComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UPanelDefinition* PanelDefinition;

	UPROPERTY()
	TArray<FEntryToCreate> SortedLayerEntries;
protected:
	virtual void BeginPlay() override;

public:
	void BuildSortedWidgetList();
	void SpawnHighestPriorityWidget();
	void SetNewWidget(FEntryToCreate LocalEntry);
	void SortLayers(TArray<FEntryToCreate>& TempArray);

};
