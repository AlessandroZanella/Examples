#include <iostream>
#include <list>
#include <random>

using namespace std;

const int sizeDensityArray = 10;
const int sizePositionArray = 5;

typedef struct
{
	int density;
	int time;
} DensityMeasure;

typedef struct
{
	int position;
	int time;
} PositionMeasure;

DensityMeasure _defMes[sizeDensityArray];
int densityStartIdx = 0;
int densityLastIdx = 0;

PositionMeasure _posMes[sizePositionArray];
int positionStartIdx = 0;
int positionEndIdx = 0;

void MeasureDensityReady(int density, int time_us)
{
	DensityMeasure dm;
	dm.density = density;
	dm.time = time_us;
	_defMes[densityLastIdx] = dm;
	densityLastIdx = (densityLastIdx + 1) % sizeDensityArray;
}

void MeasurePositionReady(int position_mm, int time_us)
{
	PositionMeasure pm;
	pm.position = position_mm;
	pm.time = time_us;
	_posMes[positionStartIdx] = pm;
}

void Elaboration(
	int min_pos_mm,
	int max_pos_mm,
	int* mean_density,
	int* min_density,
	int* median_density)
{
}

void PopulateMeasure()
{
	MeasureDensityReady(300, 150);
	MeasureDensityReady(600, 450);
	MeasureDensityReady(700, 550);
	MeasureDensityReady(550, 600);
	MeasureDensityReady(400, 800);
	MeasureDensityReady(350, 950);
	MeasureDensityReady(500, 1200);
	MeasureDensityReady(600, 1400);
	MeasureDensityReady(850, 1500);
	MeasureDensityReady(600, 1650);

	MeasurePositionReady(250, 30);
	MeasurePositionReady(750, 900);
	MeasurePositionReady(1300, 1000);
	MeasurePositionReady(1560, 1250);
}

int main()
{
	for(int i=0; i<400; ++i)
	{
		MeasureDensityReady(i, i);
	}
}
