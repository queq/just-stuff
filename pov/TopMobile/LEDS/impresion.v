`timescale 1ns / 1ps
module impresion( clk,load_leds,leds,ledsOut,T);
	input 		clk;
	input			load_leds;
	input [3:0]	 T;
	input [15:0]	 leds;
	output reg [15:0] ledsOut;
	reg [15:0] 	temp;
	reg [3:0] 	con_tem;
	 
always @(posedge clk)
begin
		if (load_leds == 1)begin
		temp<=leds;
		con_tem<=0;
		end
		else if(con_tem<T)begin
		temp <= {temp[0],temp[15:1]};
		con_tem <= con_tem+1;
		end else temp <= temp;
end 
always @(temp)begin 
	if(con_tem==T) ledsOut <=temp; // ~temp;
	else ledsOut <= 16'b0000000000000000;
	end
endmodule
