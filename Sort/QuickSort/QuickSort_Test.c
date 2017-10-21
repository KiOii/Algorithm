#include <stdio.h>
/*********************************************************/
typedef int          mElemType;
typedef mElemType*   mArray;
typedef unsigned int mIndex;
/*********************************************************/
void QuickSort(mArray S, mIndex begin, mIndex end);
void Partition(mArray S, mIndex begin, mIndex end,mIndex *pos);
void Exchange(mElemType *e1, mElemType *e2);
/*********************************************************/
int main()
{
	mElemType m[] = { 5,2,5,6,9,10,21,4,3,9 };
	QuickSort(m, 0, 9);
	return 0;
}

void QuickSort(mArray S, mIndex begin, mIndex end)
{
	if (begin < end)
	{
		mIndex pos = 0;

		Partition(S, begin, end, &pos);
		QuickSort(S, begin, pos - 1);
		QuickSort(S, pos + 1, end);
	}
}

void Partition(mArray S, mIndex begin, mIndex end,mIndex *pos)
{
	mIndex pos_index = begin;
	mIndex visit_index = begin + 1;
	mElemType key = S[begin];
	
	for (; visit_index <= end; ++visit_index)
	{
		if (key > S[visit_index])
		{
			pos_index++;
			Exchange(&S[pos_index], &S[visit_index]);
	
		}
	}
	Exchange(&S[begin], &S[pos_index]);
	*pos = pos_index;
}

void Exchange(mElemType *e1, mElemType *e2)
{
	mElemType e = *e1;
	*e1 = *e2;
	*e2 = e;
}
