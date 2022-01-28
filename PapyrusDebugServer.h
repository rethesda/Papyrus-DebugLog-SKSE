#pragma once
#include <DebugSession.h>
#include <Websocket.h>

namespace PapyrusDebugLogServer
{
	class PapyrusDebugServer
	{
	public:
		PapyrusDebugServer();
		~PapyrusDebugServer();
		
		bool Listen();

	private:
		PapyrusDebugger* m_Debugger;

		HANDLE m_Thread;
		server m_server;

		websocketpp::connection_hdl m_ConnectionHandle;

		std::basic_streambuf<char>* m_StreamBuffer;

		int ListenInternal();

		void Send(std::string message);
		
		void HandleMessage(websocketpp::connection_hdl hdl, message_ptr msg);
		void HandleOpen(websocketpp::connection_hdl hdl);
		void HandleClose(websocketpp::connection_hdl hdl);
		
		static DWORD WINAPI ListenThreadStart(void* param);
	};
}
