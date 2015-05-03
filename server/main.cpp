#pragma comment(lib, "User32.lib")

#define BUF_SIZE 20*1024

#include <string.h>
#include <aced.h>
#include "tchar.h"
#include <acdocman.h>


#include <boost/thread.hpp>

#include "socket.h"

int on=1, connected=0, incoming=0;

wchar_t *msge;
Socket* socketo;

void th_1();
void th_3();
boost::thread workerThread;

extern "C" AcRx::AppRetCode
acrxEntryPoint(AcRx::AppMsgCode msg, void* appId)
{
switch (msg) 
  {
    case AcRx::kInitAppMsg:

      acrxDynamicLinker->unlockApplication(appId);
      acrxDynamicLinker->registerAppMDIAware(appId); 

	  msge = new wchar_t[BUF_SIZE];
      socketo = new Socket(BUF_SIZE);

	  if (socketo->start()) acutPrintf(_T("\nSocket Error.\n"));
	  else acutPrintf(_T("\nSocket Ok.\n"));

	  	workerThread = boost::thread(boost::bind(th_1));
	  	SetTimer(NULL, 1, 1,(TIMERPROC)th_3);

    break;
          
    case AcRx::kUnloadAppMsg:
      KillTimer(NULL, 1);
		break;
    default:
			
      break;
  }
  return AcRx::kRetOK;
}

void th_1(){
	while(on){  
	if (!connected) if (!socketo->connect()) connected = 1;
	if (connected == 1) if (!(incoming = socketo->read(msge))) connected = 0;
	}
}

void th_3(){

	if (incoming>0){
			incoming = 0;
	switch (socketo->code(msge)){
		
        case 1:
			for (int i=0; i< (BUF_SIZE-3); i++)
				msge[i] = msge[i+3];
			acDocManager->sendStringToExecute(curDoc(), msge);
			socketo->send_ok();
			break;

		default:
			break;
	}
	}

}
