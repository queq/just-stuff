module top_receptor (ready, clk, reset, CharSalida, rxd, String);

	input clk;
	input reset;
	input rxd;

  output [0:6] CharSalida;
   
   output ready;

  output [0:76] String;
   
  // wire [0:76] String;
   wire [0:6] 	 char;
   wire 	 clk_2;
   wire 	 WriteChar;
   wire 	 error;
   wire [2:0] 	 char_count;
   wire 	 CharReady;
   wire 	 StringReady;
   wire 	 WriteString;
   wire 	 PossibleStart;
   wire 	 check;
   wire 	 parity;
   wire [3:0] 	 str_count;
   
   counter counter(.clk_2(clk_2), .char_count(char_count), .str_count(str_count), .reset(reset), .WriteChar(WriteChar), .WriteString(WriteString));
   
   Wait Wait(.reset(reset), .clk(clk), .clk_2(clk_2), .check(check), .PossibleStart(PossibleStart), .WriteChar(WriteChar));
   
   StringComparator StringComparator(.str_count(str_count), .StringReady(StringReady));
   
   Parity Parity(.char(char), .rxd(rxd), .parity(parity));
   
   mstring mstring(.WriteString(WriteString), .char(char), .String(String), .reset(reset), .clk_2(clk_2));
   
   control_o control_o(.reset(reset), .rxd(rxd), .StringReady(StringReady), .CharReady(CharReady), .parity(parity), .ready(ready), .error(error), .WriteChar(WriteChar), .WriteString(WriteString), .PossibleStart(PossibleStart), .clk_2(clk_2), .check(check));

   CharComparator CharComparator (.char_count(char_count), .CharReady(CharReady));
   
   Char Char (.clk_2(clk_2), .rxd(rxd), .WriteChar(WriteChar), .error(error), .reset(reset), .char(char));

   test test (.String(String), .CharSalida(CharSalida), .clk(clk), .ready(ready), .reset(reset));

   	
endmodule // top_receptor
