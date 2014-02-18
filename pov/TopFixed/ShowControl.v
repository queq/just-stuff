module ShowControl(clk, enhe, outcont, Reset, change, Z, Start, EN, creaenhe, Init, Shift, Ready, Cycend, rst, Beg, scrinit);


 input clk, enhe, outcont, Reset, change, Z, Ready, Cycend;

 output reg Start, EN, creaenhe, Init, Shift, rst, Beg;
 output reg [2:0]scrinit;
 reg [3:0] current_state;
 reg [3:0] next_state;

 parameter INITIAL1=4'b0000, INITIAL2=4'b0001,INITIAL3=4'b0010, INITIAL4=4'b0011, CLEARSCREEN=4'b0100,  LOADCAD=4'b0101, CHECKCON=4'b0110, CREATESTATE=4'b0111, CHECKENHE=4'b1000, PRINTSCR=4'b1001, INITIAL5=4'b1010, INITIAL6=4'b1011, INITIAL7=4'b1100, PRIENHE=4'b1101, RESETSCREEN=4'b1110 ,RESETSTATE=4'b1111;

initial begin
	current_state<=INITIAL1;
end

always @(enhe or outcont or Reset or change or Z or current_state or Ready or Cycend) begin
	case(current_state)
		INITIAL1: begin
			Start=1;			
			creaenhe=0;
			Init=0;
			Shift=0;
			rst=0;
			Beg=0;
			scrinit=3'b101;			
			if(~Ready) begin
				EN=1;
				next_state<=INITIAL1;
			end
			else begin
				EN=0;
				if(Cycend) begin
					Beg=1;
					next_state<=INITIAL2;
				end
				else
					next_state<=INITIAL1;
			end
		end

	INITIAL2: begin
			Start=1;			
			creaenhe=0;
			Init=0;
			Shift=0;
			rst=0;
			Beg=0;
			scrinit=3'b101;			
			if(~Ready) begin
				EN=1;
				next_state<=INITIAL2;
			end
			else begin
				EN=0;
				if(Cycend) begin
					Beg=1;
					next_state<=INITIAL3;
				end
				else
					next_state<=INITIAL2;
			end
		end

	INITIAL3: begin
			Start=1;			
			creaenhe=0;
			Init=0;
			Shift=0;
			rst=0;
			Beg=0;
			scrinit=3'b101;			
			if(~Ready) begin
				EN=1;
				next_state<=INITIAL3;
			end
			else begin
				EN=0;
				if(Cycend) begin
					Beg=1;
					next_state<=INITIAL4;
				end
				else
					next_state<=INITIAL3;
			end
		end

	INITIAL4: begin
			Start=1;			
			creaenhe=0;
			Init=0;
			Shift=0;
			rst=0;
			Beg=0;
			scrinit=3'b001;			
			if(~Ready) begin
				EN=1;
				next_state<=INITIAL4;
			end
			else begin
				EN=0;
				if(Cycend) begin
					Beg=1;
					next_state<=INITIAL5;
				end
				else
					next_state<=INITIAL4;
			end
		end

		INITIAL5: begin
			Start=1;
			creaenhe=0;
			Init=0;
			Shift=0;
			rst=0;
			Beg=0;
			scrinit=3'b010;			
			if(~Ready) begin
				EN=1;
				next_state<=INITIAL5;
			end
			else begin
				EN=0;
				if(Cycend) begin
					Beg=1;
					next_state<=INITIAL6;
				end
				else
					next_state<=INITIAL5;
			end
		end

		INITIAL6: begin
			Start=1;			
			creaenhe=0;
			Init=0;
			Shift=0;
			rst=0;
			Beg=0;
			scrinit=3'b011;			
			if(~Ready) begin
				EN=1;
				next_state<=INITIAL6;
			end
			else begin
				EN=0;
				if(Cycend) begin
					Beg=1;
					next_state<=INITIAL7;
				end
				else
					next_state<=INITIAL6;
			end
		end

		INITIAL7: begin
			Start=1;
			creaenhe=0;
			Init=0;
			Shift=0;
			rst=0;
			Beg=0;
			scrinit=3'b100;
			if(~Ready) begin
				EN=1;
				next_state<=INITIAL7;
			end
			else begin
				EN=0;
				if(Cycend) begin
					Beg=1;
					next_state<=LOADCAD;
				end
				else
					next_state<=INITIAL7;
			end
		end

		LOADCAD: begin
			Start=1;
			EN=1;
			creaenhe=0;
			Init=1;
			Shift=0;
			rst=0;
			Beg=1;
			scrinit=3'b000;
			if (Reset==1'b1) 
				next_state<=RESETSTATE;
			else begin
				if (change == 1'b1) 
					next_state<=CLEARSCREEN;
				else 
					next_state<=LOADCAD;
			end           
		end

		CHECKCON: begin
			Start=0;
			EN=1;
			creaenhe=0;
			Init=0;
			Shift=0;
			rst=0;
			Beg=1;
			scrinit=3'b000;
			if (Reset==1'b1) 
				next_state<=RESETSTATE;
			else begin
				if (outcont == 1'b1)
					next_state<=CHECKENHE;
				else 
					next_state<=CREATESTATE;
			end          
		end

		CREATESTATE: begin
			Start=0;
			EN=1;
			creaenhe=0;
			Init=0;
			Shift=1;
			rst=0;
			Beg=1;
			scrinit=3'b000;
			if (Reset==1'b1) 
				next_state<=RESETSTATE;
			else begin
				next_state<=CHECKCON;
			end
		end

		CHECKENHE: begin
			Start=0;
			EN=1;
			creaenhe=0;
			Init=0;
			Shift=0;
			rst=0;
			Beg=1;
			scrinit=3'b000;
			if (Reset==1'b1) 
				next_state<=RESETSTATE;
			else begin
				if (enhe == 1'b0) 
					next_state<=PRINTSCR;
				else 
					next_state<=PRIENHE;
			end
		end

	PRIENHE: begin
			Start=1;
			creaenhe=1;
			Init=0;
			Shift=0;
			rst=0;
			Beg=0;
			scrinit=3'b110;			
			if (Reset==1'b1) begin
				EN=1;
				next_state<=RESETSTATE;
			end
			else begin	
				if(~Ready) begin			
					EN=1;
					next_state<=PRIENHE;
				end
				else begin
					EN=0;
					if(Cycend) begin
						if(Z)
							next_state<=LOADCAD;
						else
							next_state<=CHECKCON;
					end
					else
						next_state<=PRIENHE;
				end
			end
		end
		
	PRINTSCR: begin
			Start=1;
			creaenhe=0;
			Init=0;
			Shift=0;
			rst=0;
			Beg=0;
			scrinit=3'b110;			
			if (Reset==1'b1) begin
				EN=1;
				next_state<=RESETSTATE;
			end
			else begin	
				if(~Ready) begin			
					EN=1;
					next_state<=PRINTSCR;
				end
				else begin
					EN=0;
					if(Cycend) begin
						if(Z)
							next_state<=LOADCAD;
						else
							next_state<=CHECKCON;
					end
					else
						next_state<=PRINTSCR;
				end
			end
		end

		CLEARSCREEN: begin
			Start=1;
			creaenhe=0;
			Init=1;
			Shift=0;
			rst=0;
			Beg=0;
			scrinit=3'b000;	
			if (Reset==1'b1) begin
				EN=1;
				next_state<=RESETSTATE;
			end
			else begin	
				if(~Ready) begin
					EN=1;
					next_state<=CLEARSCREEN;
				end
				else begin
					EN=0;
					if(Cycend)
						next_state<=CHECKCON;
					else
						next_state<=CLEARSCREEN;
				end
			end
		end

		RESETSTATE: begin
			Start=0;
			EN=1;
			creaenhe=0;
			Init=0;
			Shift=0;
			rst=1;
			Beg=1;
			scrinit=3'b000;
			next_state<=RESETSCREEN;
		end

		RESETSCREEN: begin
			Start=1;
			creaenhe=0;
			Init=1;
			Shift=0;
			rst=0;
			Beg=0;
			scrinit=3'b000;			
			if (Reset==1'b1) begin
				EN=1;
				next_state<=RESETSTATE;
			end
			else begin	
				if(~Ready) begin			
					EN=1;
					next_state<=RESETSCREEN;
				end
				else begin
					EN=0;
					if(Cycend)
						next_state<=LOADCAD;
					else
						next_state<=RESETSCREEN;
				end
			end
		end

		default begin
			Start=0;
			EN=0;
			creaenhe=0;
			Init=0;
			Shift=0;
			rst=1;
			Beg=1;
			scrinit=3'b000;
			next_state<=RESETSTATE;
		end                
	endcase
end

always @(posedge clk) begin
	current_state<=next_state;
end

endmodule
