`timescale 1ns / 1ps

module top_movil_TB;

   reg  clk;
//   reg 	start;
   reg 	reset;
   reg rxd;
   
  // wire [0:76] String;
   wire [15:0] ledsOut;

   top_movil uut ( .clk(clk), .rxd(rxd), .reset(reset), .ledsOut(ledsOut));
   initial  begin  // Process for clk
     forever
       begin
	  #5
            clk = 1'b0;
	  #5
	    clk = 1'b1;
       end
   end

/*	initial begin
	   reset=1;
	#100	
	reset=0;
	start=0;
	#200
	reset=1;
	#1000
	start=1;
	#20
	reset=0;
	#13998680
	reset=1;
	#200
	reset=0;
	end*/

   initial begin
	reset=1;
	#200
	reset=0;
	rxd =1;
      #2000
	rxd=0; // simulacion de ruido
      #40
	rxd=1;
      #208280
	rxd=0; // Bit de Start 1
      #104160
	rxd=0;
      #104160
	rxd=1;
      #104160
	rxd=1;
      #104160
	rxd=0;
      #104160
	rxd=0;
      #104160
	rxd=1;
      #104160
	rxd=1; // Se termina char 0110011
      #104160
	rxd=0; // Bit de Paridad
      #104160
	rxd=1; // Bit de Stop
      #104160
	rxd=0; // Bit de Start 2
      #104160
	rxd=0;
      #104160
	rxd=0;
      #104160
	rxd=1;
      #104160
	rxd=0;
      #104160
	rxd=1;
      #104160
	rxd=0;
      #104160
	rxd=1; // Se termina char 0010101
      #104160
	rxd=1; // Bit de Paridad
      #104160
	rxd=1; // Bit de Stop
      #104160
	rxd=0; // Bit de Start 3
      #104160
	rxd=1;
      #104160
	rxd=1;
      #104160
	rxd=1;
      #104160
	rxd=0;
      #104160
	rxd=0;
      #104160
	rxd=1;
      #104160
	rxd=0; // Se termina char 1110010
      #104160
	rxd=0; // Bit de Paridad
      #104160
	rxd=1; // Bit de Stop
      #104160
	rxd=0; // Bit de Start 4
      #104160
	rxd=0;
      #104160
	rxd=1;
      #104160
	rxd=0;
      #104160
	rxd=1;
      #104160
	rxd=1;
      #104160
	rxd=0;
      #104160
	rxd=0; // Se termina char 0101100
      #104160
	rxd=1; // Bit de Paridad
      #104160
	rxd=1; // Bit de Stop
      #104160
	rxd=0; // Bit de Start 5
      #104160
	rxd=1;
      #104160
	rxd=1;
      #104160
	rxd=1;
      #104160
	rxd=0;
      #104160
	rxd=0;
      #104160
	rxd=0;
      #104160
	rxd=0; // Se termina char 1110000
      #104160
	rxd=1; // Bit de Paridad
      #104160
	rxd=1; // Bit de Stop
      #104160
	rxd=0; // Bit de Start 6
      #104160
	rxd=0;
      #104160
	rxd=0;
      #104160
	rxd=1;
      #104160
	rxd=1;
      #104160
	rxd=1;
      #104160
	rxd=1;
      #104160
	rxd=1; // Se termina char 0011111
      #104160
	rxd=1; // Bit de Paridad
      #104160
	rxd=1; // Bit de Stop
      #104160
	rxd=0; // Bit de Start 7
      #104160
	rxd=0;
      #104160
	rxd=0;
      #104160
	rxd=1;
      #104160
	rxd=0;
      #104160
	rxd=1;
      #104160
	rxd=0;
      #104160
	rxd=0; // Se termina char 0010100
      #104160
	rxd=0; // Bit de Paridad
      #104160
	rxd=1; // Bit de Stop
      #104160
	rxd=0; // Bit de Start 8
      #104160
	rxd=0;
      #104160
	rxd=0;
      #104160
	rxd=1;
      #104160
	rxd=1;
      #104160
	rxd=0;
      #104160
	rxd=0;
      #104160
	rxd=1; // Se termina char 0011001
      #104160
	rxd=1; // Bit de Paridad
      #104160
	rxd=1; // Bit de Stop
      #104160
	rxd=0; // Bit de Start 9
      #104160
	rxd=1;
      #104160
	rxd=1;
      #104160
	rxd=0;
      #104160
	rxd=0;
      #104160
	rxd=1;
      #104160
	rxd=1;
      #104160
	rxd=0; // Se termina char 1100110
      #104160
	rxd=0; // Bit de Paridad
      #104160
	rxd=1; // Bit de Stop
      #104160
	rxd=0; // Bit de Start 10
      #104160
	rxd=1;
      #104160
	rxd=1;
      #104160
	rxd=1;
      #104160
	rxd=1;
      #104160
	rxd=1;
      #104160
	rxd=1;
      #104160
	rxd=0; // Se termina char 1111110
      #104160
	rxd=0; // Bit de Paridad
      #104160
	rxd=1; // Bit de Stop
      #104160
	rxd=0; // Bit de Start 11
      #104160
	rxd=0;
      #104160
	rxd=1;
      #104160
	rxd=1;
      #104160
	rxd=0;
      #104160
	rxd=0;
      #104160
	rxd=0;
      #104160
	rxd=0; // Se termina char 0110000
      #104160
	rxd=1; // Bit de Paridad
      #104160
	rxd=1; // Bit de Stop y queda en 1 como IDLE	
   end // initial begin
    

   initial begin: TEST_CASE
     $dumpfile("top_movil_TB.vcd");
     $dumpvars(-1, uut);
     #32000000 $finish;
   end

endmodule

