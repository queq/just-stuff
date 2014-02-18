`timescale 1ns / 1ps
module top_string_tb;
	reg clk, new, reset;
	reg [6:0] char;
	wire complete, change;
	wire [76:0] string;

	top_string uut ( .new(new), .clk(clk), .btn1(reset), .char(char), .string(string));
	
	initial begin  // Initialize Inputs
		new=0;
		reset=1;
		char=7'b0000000;
		clk=1;
		#100
		reset=0;

	end	
     
	initial begin 
		forever begin		
		#600		
		new=1;
		#100
		new=0;
		#400
		new=1;
		#100
		new=0;
		#400
		new=1;
		#100
		new=0;
		#400
		new=1;
		#100
		new=0;
		#400
		new=1;
		#100
		new=0;
		#400
		new=1;
		#100
		new=0;
		#400
		new=1;
		#100
		new=0;
		#400
		new=1;
		#100
		new=0;
		#400
		new=1;
		#100
		new=0;
		#400
		new=1;
		#100
		new=0;
		end
	end 
	
	initial begin 
		forever begin		
		#600
		char=7'b1111011;		//o
		#500
		char=7'b0001000;	//borrar	
		#500
		char=7'b0111111;			//virgulilla
		#500
		char=7'b0000111; //p 
		#500
		char=7'b0111111;			//virgulilla
		#500
		char=7'b0111011; 		//ene
		#500
		char=7'b0000111; //p
		#500
		char=7'b0010000; //enter
		#500
		//char=7'b1000110; //uno
		char=7'b1111011;		
		#500
		char=7'b1000110; //uno
		#500
		char=0;
		end

	end 

	initial begin 
		forever begin
		#50
		clk=0;
		#50
		clk=1;		
		end
	end 
	
	initial begin: TEST_CASE
		$dumpfile("top_string_TB.vcd");
		$dumpvars(-1, uut);
		#60000 $finish;
	end

endmodule
