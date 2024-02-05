// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class MAPTEST_API MyDisjointSet
{
public:
	MyDisjointSet(int n);
	
	int Find(int u)
	{
		if (u == _parent[u])
			return u;

		//_parent[u] = Find(_parent[u]);
		//return _parent[u];

		return _parent[u] = Find(_parent[u]);
	}

	// u와 v를 합친다
	void Merge(int u, int v)
	{
		u = Find(u);
		v = Find(v);

		if (u == v)
			return;

		if (_rank[u] > _rank[v])
		{
			//swap(u, v);
			int temp = u;
			u = v;
			v = temp;
		}
			

		// rank[u] <= rank[v] 보장됨
		_parent[u] = v;

		if (_rank[u] == _rank[v])
			_rank[v]++;
	}

private:
	TArray<int32> _parent;
	TArray<int32> _rank;
};
