`timescale 1ns / 1ps
module dir_ascci( //direccion inicial de cada ascci + col
    input [10:0]dir_in,
    input clk,
	 input [3:0] col,
input done,
    output reg [10:0] dir_rom
    );
reg [10:0]temp;
parameter d=479;
always @(posedge done) begin
		temp<=dir_in;
		end
always @(posedge clk) begin
		dir_rom<=temp+col-d;
		end
		
endmodule
