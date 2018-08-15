#include "Subsection.h"
#include "GasBase.h"
#include "Door.h"

//Iterates through all gas volumes in the subsection and updates them
void ASubsection::UpdateAllGas()
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AGasBase::StaticClass(), FoundActors);
	for (int x = 0; x < FoundActors.Num(); x++)
	{
		if (Cast<AGasBase>(FoundActors[x])->subsection == this)
			Cast<AGasBase>(FoundActors[x])->UpdateGasStatus();	
	}
}
