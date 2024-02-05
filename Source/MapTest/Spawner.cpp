// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawner.h"
#include "MyDisjointSet.h"

// Sets default values
ASpawner::ASpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASpawner::GenerateMap(int32 size, TArray<int32>& yArr, TArray<int32>& xArr)
{
	for (int32 y = 0; y < size; y++)
	{
		for (int32 x = 0; x < size; x++)
		{
			if (x % 2 == 0 || y % 2 == 0)
				;// wall
			else
				;// floor
		}
	}

	TArray<CostEdge> edges;

	for (int32 y = 0; y < size; y++)
	{
		for (int32 x = 0; x < size; x++)
		{
			if (x % 2 == 0 || y % 2 == 0)
				continue;

			if (x < size - 2)
			{
				const int32 randValue = FMath::RandRange(0, 100);
				edges.Add(CostEdge{ randValue, Pos{y, x}, Pos{y, x + 2} });
			}

			if (y < size - 2)
			{
				const int32 randValue = FMath::RandRange(0, 100);
				edges.Add(CostEdge{ randValue, Pos{y, x}, Pos{y + 2, x} });
			}
		}
	}

	// sort edges
	edges.Sort([](const CostEdge& a, const CostEdge& b) { return a.cost < b.cost; });

	for(auto& edge : edges)
	{
		UE_LOG(LogTemp, Warning, TEXT("Cost : %d"), edge.cost);
	}

	MyDisjointSet sets(size * size);

	for (CostEdge& edge : edges)
	{
		int u = edge.u.y * size + edge.u.x;
		int v = edge.v.y * size + edge.v.x;
		// 같은 그룹이면 스킵 (안 그러면 사이클 발생)
		if (sets.Find(u) == sets.Find(v))
			continue;

		// 두 그룹을 합친다
		sets.Merge(u, v);

		// 맵에 적용
		int y = (edge.u.y + edge.v.y) / 2;
		int x = (edge.u.x + edge.v.x) / 2;
		//_tile[y][x] = TileType::EMPTY;

		yArr.Add(y);
		xArr.Add(x);
	}

}

// Called every frame
void ASpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

