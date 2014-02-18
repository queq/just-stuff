`timescale 1ns / 1ps
module cont_ram(  //direccion de las 160 columnas en ram para escr
    input clk,
    input add_dirram,
    input reset_dirram,
    output reg [7:0]dir_ram
    );
reg [7:0] temp;
always @(posedge clk) begin
	
	 if (reset_dirram == 1)	temp <= 8'b00000000;
		else if (add_dirram == 1) temp <= temp+1;
		else temp<=temp;
	end
	
always @(temp) begin
		dir_ram <= temp;
	end

endmodule
