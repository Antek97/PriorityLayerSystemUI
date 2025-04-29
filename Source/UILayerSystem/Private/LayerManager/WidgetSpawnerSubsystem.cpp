#include "LayerManager/WidgetSpawnerSubsystem.h"
#include "Blueprint/UserWidget.h"

UUserWidget* UWidgetSpawnerSubsystem::SpawnWidget(TSoftClassPtr<UUserWidget> WidgetClass)
{
    if (!WidgetClass.IsValid())
    {
        WidgetClass.LoadSynchronous();
    }

    if (TSubclassOf<UUserWidget> LoadedClass = WidgetClass.Get())
    {
        if (UWorld* World = GetWorld())
        {
            return CreateWidget<UUserWidget>(World, LoadedClass);
        }
    }

    return nullptr;
}

void UWidgetSpawnerSubsystem::AddToViewport(UUserWidget* Widget, int32 ZOrder)
{
    if (Widget)
    {
        Widget->AddToViewport(ZOrder);
    }
}
