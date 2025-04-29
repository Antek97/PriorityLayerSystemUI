
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Blueprint/UserWidget.h"
#include "PanelDefinition.generated.h"

USTRUCT(BlueprintType)
struct FLayerUI
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName NamePanel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftClassPtr<UUserWidget> LayerWidget;
};

UCLASS()
class UILAYERSYSTEM_API UPanelDefinition : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PanelDefinition", meta = (ToolTip = "Key: Unique priority level of the layer. Value: Widget class associated with that layer."))
	TMap<int32, FLayerUI> PanelOverrides;
};


