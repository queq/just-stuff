`timescale 1ns / 1ps
module control_leds(
	input clk,
	input run_efect,
	output reg leer_ram,
	output reg leer_rom
	);
	
	reg [6:0] current_state;
	reg [6:0] next_state;
	
	parameter start=7'b0000000, state_1=7'b0000001, state_2=7'b0000010, state_3=7'b0000011, state_4=7'b0000100, state_5=7'b0000101;//,state_1p=7'b0000110; 

	always @(top_ascci or done or top_col or leer_ram or new_string or current_state)begin
		case(current_state)
     		start: 	begin			//encendido esperando new string
						
								add_dirram=1'b0;
								reset_dirram=1'b1;
								add_col=1'b0;
								reset_col=1'b1;
								add_ascci=1'b0;
								reset_ascci=1'b1;
								leer_rom=1'b0;	
								init=0;
			
						if (new_string==1'b1) next_state<=state_1;
						else next_state<=start;
					end
			
			state_1:	begin 		//inicial multiplicacion
								add_dirram=1'b0;
								reset_dirram=1'b0;
								add_col=1'b0;
								reset_col=1'b0;
								add_ascci=1'b0;
								reset_ascci=1'b0;
								leer_rom=1'b0;
								init=1;
						
						next_state<=state_2;
					end
			/*state_1p:	begin 		//doble inint multiplicacion
								add_dirram=1'b0;
								reset_dirram=1'b0;
								add_col=1'b0;
								reset_col=1'b0;
								add_ascci=1'b0;
								reset_ascci=1'b0;
								leer_rom=1'b0;
								init=1;
						
						next_state<=state_2;
					end*/
			state_2:	begin 		//esperando fin multiplicacion
								add_dirram=1'b0;
								reset_dirram=1'b0;
								add_col=1'b0;
								reset_col=1'b0;
								add_ascci=1'b0;
								reset_ascci=1'b0;
								leer_rom=1'b0;
								init=0;
						if(done==1'b1) next_state<=state_3;
					else next_state<=state_2;
					end
			
			state_3:	begin 		//lee y guarda columna de rom a ram
								add_dirram=1'b0;
								reset_dirram=1'b0;
								add_col=1'b0;
								reset_col=1'b0;
								add_ascci=1'b0;
								reset_ascci=1'b0;
								leer_rom=1'b1;
								init=0;

						next_state<=state_4;
					end
			state_4:	begin		//pasa a sigiente columna
								add_dirram=1'b1;
								reset_dirram=1'b0;
								add_col=1'b1;
								reset_col=1'b0;
								add_ascci=1'b0;
								reset_ascci=1'b0;
								leer_rom=1'b1;
								init=0;
						if (top_col == 1'b1) next_state<=state_5;
						else next_state<=state_3;
						
					end
			state_5:	begin		// pasa a sigiente ascci
								add_dirram=1'b1;
								reset_dirram=1'b0;
								add_col=1'b0;
								reset_col=1'b1;
								add_ascci=1'b1;
								reset_ascci=1'b0;
								leer_rom=1'b0;
								init=0;
						if (top_ascci==1'b1)next_state<=start;
						else next_state<=state_1;

					end
			/*state_4:	begin		// Aumento de vueltas
								add_dirram=1'b0;
								reset_dirram=1'b1;
								add_col=1'b0;
								reset_col=1'b1;
								add_ascci=1'b0;
								reset_ascci=1'b1;
								enram=1'b0;
								leer_ram=1'b0;
						
						if (top_1==1'b1)next_state<=state_5;
						else next_state<=state_1;
			
					end*/
			default:
					begin
								add_dirram=1'b0;
								reset_dirram=1'b0;
								add_col=1'b0;
								reset_col=1'b0;
								add_ascci=1'b0;
								reset_ascci=1'b0;
								leer_rom=1'b0;
								init=0;
						next_state<=start;
					end
		endcase
	end	

	always @(negedge clk) begin
	    current_state<=next_state;	
	end
endmodule
