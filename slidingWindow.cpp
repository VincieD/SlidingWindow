/*Sliding window method in C++ */

// we need to define reign of interest

using namespace std;
#include "slidingWindow.hpp"
#include <iomanip>      // std::setw
#include <iostream>


//typedef std::vector<int> int_vec_t;    // or whatever you
// int_vec_t v;

///////////////////// Public variables ///////////////////////////


///////////////////// Private variables  ///////////////////////////

///////////////////// Public functions ///////////////////////////

SlidingWindow::SlidingWindow()
{

    // for small projects is better to use the std namespace directly before the used 
    //std::vector<std::vector<unsigned char> > matrix(dim_x, std::vector<unsigned char>(dim_y));
    //std::vector<std::vector<unsigned char> > rects(winXsize, std::vector<unsigned char>(winYsize));    
}

void SlidingWindow::matrixFillIn(std::vector<std::vector<unsigned char> >& arrayToFillIn, unsigned char step)
{
	for(unsigned int i=0;i<arrayToFillIn.size();i+=step)
	{
		// windows Height shall not be greater than image rows
		if(i>arrayToFillIn.size())
			{break;}
	  
		for(unsigned int j=0;j<arrayToFillIn[0].size();j+=step)    
		{
			// windows Width shall not be greater than image cols
			if(j>arrayToFillIn[0].size())
				{break;}


			arrayToFillIn[i].at(j) = (unsigned char)(255*rand());
		}
	} 
}


void SlidingWindow::matrixPrintOut(std::vector<std::vector<unsigned char> >& arrayToPrintOut, unsigned char step)
{
	for (unsigned int i = 0; i<arrayToPrintOut.size(); i += step)
	{
		// windows Height shall not be greater than image rows
		if (i>arrayToPrintOut.size())
			{break;}
	  
		for (unsigned int j = 0; j<arrayToPrintOut[0].size(); j += step)
		{
			// windows Width shall not be greater than image cols
			if (j>arrayToPrintOut[0].size())
				{break;}
			//cout << "index X: " << (int)i<< " index Y: " << (int)j << endl;
			std::cout << setw(3) << int(arrayToPrintOut[i][j]) << " ";
		}
		cout << endl;
	} 
}

void SlidingWindow::matrixPrintOut(std::vector<std::vector<int> >& arrayToPrintOut, unsigned char step)
{
	for (unsigned int i = 0; i<arrayToPrintOut.size(); i += step)
	{
		// windows Height shall not be greater than image rows
		if (i>arrayToPrintOut.size())
			{break;}
	  
		for (unsigned int j = 0; j<arrayToPrintOut[0].size(); j += step)
		{
			// windows Width shall not be greater than image cols
			if (j>arrayToPrintOut[0].size())
				{break;}
		
			std::cout << setw(4) << int(arrayToPrintOut[i][j]) << " ";
		}
		cout << endl;
	} 
}


bool SlidingWindow::getSlidingWindows(std::vector<std::vector<unsigned char> >& image, std::vector<std::vector<unsigned char> >& window, std::vector<std::vector<unsigned char> >& schrinkedWindow, unsigned char regionOfIntX, unsigned char regionOfIntY)
{
	int indexX = 0, indexY = 0;
	int winWidth = window.size();
	int winHeight = window[0].size();
	bool status = true;


	float ratio_X = (float)(((float)(schrinkedWindow.size()) / window.size()));
	float ratio_Y = (float)(((float)(schrinkedWindow[0].size()) / window[0].size()));

	if (regionOfIntX > (image.size() - winWidth))
	{
		status = false;
	}

	if (regionOfIntY > (image[0].size() - winHeight))
	{
		status = false;
	}

	// go inside the sliding window code - and copy the data into window vector
	if (status == true)
	{
		for (int i = regionOfIntX; i < ((winWidth + regionOfIntX)-1); i++ )
		{
			// windows Height shall not be greater than image rows
			for (int j = regionOfIntY; j < ((winHeight + regionOfIntY)-1); j++ )
			{
				// append to the rects another vector which is called rect
				//window[indexX].at(indexY) = (unsigned char)(image[i][j]);
				schrinkedWindow[int(indexX*ratio_X)].at(int(indexY*ratio_Y)) = (unsigned char)(image[i][j]);
				indexY++;
			}
			indexX++;
			// Y index has to be clear to zero - otherwise index overflow
			indexY = 0;
		}
	}

   return status;
}


void SlidingWindow::schrinking(std::vector<std::vector<unsigned char> >& schrinkedWindow, std::vector<std::vector<unsigned char> >& originalWindow)
{
	static float ratio_X = (float)(originalWindow.size()) / (float)(schrinkedWindow.size());
	static float ratio_Y = (float)(originalWindow[0].size()) / (float)(schrinkedWindow[0].size());
	
	for (int i=0; i < schrinkedWindow.size(); i++)
	{
		for (int j=0; j < schrinkedWindow[0].size(); j++)
		{
			schrinkedWindow[i].at(j) = originalWindow[int(i*ratio_X)][int(j*ratio_Y)];
		}
	}
}

///////////////////// Private functions ///////////////////////////

// initial idea is to calculate the energy of the subframe
// add 
//unsigned char pictureEnergy(vector<vector<unsigned char> >& subWindow, unsigned char winWidth, unsigned char winWeight)
//{
//	unsigned char energy;
//		for(unsigned char p= 0)
//		subWindow[][] = 1;
//	// Use the try catch to check the index of the array with function .at
//		try
//		{
//			subWindow.at(1000) = 0;
//		}
//		catch(std::out_of_range obj)
//		{    
//			std::cout<<obj.what()<<std::endl;
//		}
//	
//	return energy;
//}