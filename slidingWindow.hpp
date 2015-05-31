#ifndef __SLIDINGWINDOW_H_INCLUDED__
#define __SLIDINGWINDOW_H_INCLUDED__
   
   #include <iostream>
   #include <vector>
   #include <iomanip>      // std::setw
   
   class SlidingWindow
   {
      public:
         SlidingWindow();
         
         
         void matrixFillIn(std::vector<std::vector<unsigned char> >& arrayToFillIn, unsigned char step);
         void matrixPrintOut(std::vector<std::vector<unsigned char> >& arrayToPrintOut, unsigned char step);
         void matrixPrintOut(std::vector<std::vector<int> >& arrayToPrintOut, unsigned char step);
         //void getSlidingWindows(std::vector<std::vector<unsigned char> >& image, std::vector<std::vector<unsigned char> >& window,unsigned char regionOfIntX,unsigned char regionOfIntY);
         
         //unsigned int getAxisXsize();
         //unsigned int getAxisYsize();
         
         //unsigned char getWinXsize();
         //unsigned char getWinYsize();
         //void setWinXsize(unsigned char sizeX);
         //void setWinYsize(unsigned char sizeY);
         
      //private:   

         
   };

#endif

