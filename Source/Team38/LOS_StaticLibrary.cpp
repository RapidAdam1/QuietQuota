// Fill out your copyright notice in the Description page of Project Settings.


#include "LOS_StaticLibrary.h"
#include "Kismet/KismetMathLibrary.h"

TArray<FVector> ULOS_StaticLibrary::GetRelevantLOSWaypoints(FVector position, float distance)
{
	TArray<FVector> relevantWaypoints;

	for (FVector waypoint : waypoints)
	{
		if (FVector::Dist(position, waypoint) < distance)
		{
			relevantWaypoints.Add(waypoint);
		}
	}
	
	return relevantWaypoints;
}

TArray<float> ULOS_StaticLibrary::GetRelevantLOSTraceAngles(FVector position, float distance)
{
	TArray<FVector> relevantWaypoints = GetRelevantLOSWaypoints(position, distance);
	TArray<float> relevantTraceAngles;

	for (FVector waypoint : relevantWaypoints)
	{
		float waypointAngle = UKismetMathLibrary::FindLookAtRotation(position, waypoint).Yaw;

		relevantTraceAngles.Add(waypointAngle + 3.0f);
		relevantTraceAngles.Add(waypointAngle - 3.0f);
		relevantTraceAngles.Add(waypointAngle + 0.5f);
		relevantTraceAngles.Add(waypointAngle - 0.5f);
	}

	return relevantTraceAngles;
}

TArray<FVector> ULOS_StaticLibrary::SortByClockwiseOrder(TArray<FVector> array, FVector centerpoint)
{
	Algo::Sort(array, [centerpoint](const FVector& w1, const FVector& w2)
	{
		float a1 = UKismetMathLibrary::FindLookAtRotation(centerpoint, w1).Yaw;
		float a2 = UKismetMathLibrary::FindLookAtRotation(centerpoint, w2).Yaw;

		return a1 > a2;
	});

	return array;
}

void ULOS_StaticLibrary::AddLOSWaypoint(FVector position)
{
	waypoints.Add(position);
}

void ULOS_StaticLibrary::RemoveLOSWaypoint(FVector position)
{
	waypoints.Remove(position);
}
