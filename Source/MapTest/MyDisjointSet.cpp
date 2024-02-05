// Fill out your copyright notice in the Description page of Project Settings.


#include "MyDisjointSet.h"

MyDisjointSet::MyDisjointSet(int32 n) // : _parent(n), _rank(1)
{
	_parent.AddZeroed(n);
	for (int i = 0; i < n; i++)
		_parent[i] = i;

	_rank.AddZeroed(n);
	for (int i = 0; i < n; i++)
		_rank[i] = 1;
}
