`timescale 1ns / 1ps
module top_leds_TB;
    	reg  clk;
	reg run;	
	wire [15:0] ledsOut;
	//reg [7:0] dir;
	top_leds tleds(.clk(clk),.run(run),.ledsOut(ledsOut));
	
	parameter PERIOD          = 1;
   parameter real DUTY_CYCLE = 0.5;
   parameter OFFSET          = 0;
   reg [100:0] i;

   initial begin  // Initialize Inputs
      clk = 0; run = 0 ; 
   end 

   initial  begin  // Process for clk
     #OFFSET;
     forever
       begin
         clk = 1'b0;
         #(PERIOD-(PERIOD*DUTY_CYCLE)) clk = 1'b1;
         #(PERIOD*DUTY_CYCLE);
       end
   end

   initial begin 
	// Reset the system, Start the image capture process
   //#(1) string=77'b01100111001011100100010001101000001100010010010111001000100011010000011000100;//51=3.o fijo 0110000....75 72 70 65 68
 //  #(3) new_string=1'b1;
//#(6)new_string=1'b0;

	#2 run=1;
	#5 run=0;
	end
	//0101000/0101100/1000100/0101000/0101100/100010001010000101100100010000000000000000;//40 44
    
//40/44/40/44...efect 2
   initial begin: TEST_CASE
     $dumpfile("top_leds_TB.vcd");
     $dumpvars(-1, tleds);
     #10000 $finish;
   end


endmodule
