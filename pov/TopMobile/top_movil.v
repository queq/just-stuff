module top_movil (clk, rxd, reset, ledsOut, CharSalida);

   input clk;
   input reset;
   input rxd;
   
   output [15:0] ledsOut;
   output [0:6] CharSalida;
   
   
   wire [0:76] String;
   wire  	 ready;

   top_receptor top_receptor (.ready(ready), .CharSalida(CharSalida), .clk(clk), .rxd(rxd), .reset(reset), .String(String));
   top_leds tleds(.clk(clk),.string(String),.new_string(ready),.ledsOut(ledsOut));


   
endmodule // top_receptor
