

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DerelictPlayerControllerBase.generated.h"

/**
 * 
 */
UCLASS()
class DERELICTSWAMPLANDS_API ADerelictPlayerControllerBase : public APlayerController
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		TSubclassOf<class UUserWidget> FPMainWidget;
	UUserWidget* mainWidget;
	virtual void BeginPlay() override;
};
