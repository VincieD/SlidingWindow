/*Sliding window method in C++ */

// we need to define reign of interest

using namespace std;
#include "slidingWindow.hpp"
#include <iomanip>      // std::setw
#include <iostream>
//#include "stdafx.h"


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
			//arrayToFillIn[i][j] = (unsigned char)(255*rand());
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


//void getSlidingWindows(std::vector<std::vector<unsigned char> >& image, std::vector<std::vector<unsigned char> >& window,unsigned char regionOfIntX,unsigned char regionOfIntY)
//{
//	
//   
//   for(int i=regionOfIntX;i<winWidth + regionOfIntX;i+=1)
//	{
//		// windows Height shall not be greater than image rows
//		if(i>image.size())
//			{break;}
//	  
//		for(int j=regionOfIntY;j< winHeight + regionOfIntY;j+=1)    
//		{
//			// windows Width shall not be greater than image cols
//			if(j>image[0].size())
//				{break;}
//				
//			// index of our windows shall be inside the limits	
//			if((indexX > winWidth) || (indexY > winHeight))
//				{break;}		
//			
//			// append to the rects another vector which is called rect
//         window[indexX].at(indexY) = (unsigned char)(image[i][j]); 
//
//         indexY++;
//		}
//		indexX++;
//	    
//       // clearing the index otherwise it will overflow
//		if(indexX > winWidth - 1)
//		{indexX = 0;}
//		// clearing the index otherwise it will overflow
//		if(indexY > winHeight - 1)
//		{indexY = 0;}
//	}
//}
//

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