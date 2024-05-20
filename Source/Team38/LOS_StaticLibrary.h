// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "LOS_StaticLibrary.generated.h"

/**
 * 
 */
UCLASS()
class TEAM38_API ULOS_StaticLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	inline static TArray<FVector> waypoints;
	
	UFUNCTION(BlueprintCallable)
	static TArray<FVector> GetRelevantLOSWaypoints(FVector position, float distance);

	UFUNCTION(BlueprintCallable)
	static TArray<float> GetRelevantLOSTraceAngles(FVector position, float distance);

	UFUNCTION(BlueprintCallable)
	static TArray<FVector> SortByClockwiseOrder(TArray<FVector> array, FVector centerpoint);

	UFUNCTION(BlueprintCallable)
	static void AddLOSWaypoint(FVector position);

	UFUNCTION(BlueprintCallable)
	static void RemoveLOSWaypoint(FVector position);
};

