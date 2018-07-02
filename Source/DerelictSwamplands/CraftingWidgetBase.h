#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Craftable.h"
#include "CraftingWidgetBase.generated.h"

UCLASS()
class DERELICTSWAMPLANDS_API UCraftingWidgetBase : public UUserWidget
{
	GENERATED_BODY()
public:
	UCraftingWidgetBase(const FObjectInitializer& ObjectInitializer);
	UFUNCTION(BlueprintCallable, Category = Actor)
		void CraftItem(int ID);
	TArray<Craftable> craftables;
};
