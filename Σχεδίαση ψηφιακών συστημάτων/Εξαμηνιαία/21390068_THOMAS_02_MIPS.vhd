library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
entity MIPS is port(
  clk: in std_logic;
  rst: in std_logic;
  outMips: out std_logic_vector(31 downto 0));
end MIPS;

architecture structure of MIPS is

component ALU port(
  in1,in2: in std_logic_vector(31 downto 0);
  opcode: in std_logic_vector(3 downto 0);
  ALUout: out std_logic_vector(31 downto 0);
  Zero: out std_logic);
end component;
  
component RegFile port(
  RegIn1: in std_logic_vector(4 downto 0);
  RegIn2: in std_logic_vector(4 downto 0);
  RegWriteIn: in std_logic_vector(4 downto 0);
  DataWriteIn: in std_logic_vector(31 downto 0);
  RegWrite: in std_logic;
  RegOut1: out std_logic_vector(31 downto 0);
  RegOut2: out std_logic_vector(31 downto 0));
end component;
  
component DataMemory port(
  RAMin: in std_logic_vector(31 downto 0);
  WriteData: in std_logic_vector(31 downto 0);
  MemWrite: in std_logic;
  MemRead: in std_logic;
  RAMout: out std_logic_vector(31 downto 0);
  reset: in std_logic);
end component;
  
component InstructionMemory port(
  IMin: in std_logic_vector(31 downto 0);
  IMout: out std_logic_vector(31 downto 0));
end component;
 
component ControlUnit port(
  clk: in std_logic;
  OC_in: in std_logic_vector(5 downto 0);
  RegWrite: out std_logic;
  ALUSrc: out std_logic;
  ALUOp: out std_logic_vector(2 downto 0);
  MemWrite,MemRead: out std_logic;
  RegDest: out std_logic;
  MemToReg: out std_logic;
  Jump: out std_logic;
  Branch: out std_logic);
end component;
 
component ALUControl port(
  ALUOp: in std_logic_vector(2 downto 0);
  Funct: in std_logic_vector(5 downto 0);
  ALUCont_out: out std_logic_vector(3 downto 0));
end component;

component PC port(
  inPC: in std_logic_vector(31 downto 0);
  outPC: out std_logic_vector(31 downto 0);
  CLK: in std_logic;
  rst: in std_logic);
end component;

component mux2to1_5 port(
  min1,min2: in std_logic_vector(4 downto 0);
  mout: out std_logic_vector(4 downto 0);
  sel: in std_logic);
end component;

component SignExtend port(
  S_EXin: in std_logic_vector(15 downto 0);
  S_EXout: out std_logic_vector(31 downto 0));
end component;

component mux2to1_32 port(
  min1,min2: in std_logic_vector(31 downto 0);
  mout: out std_logic_vector(31 downto 0);
  sel: in std_logic);
end component;

component Adder32 port(
  in1,in2: in std_logic_vector(31 downto 0);
  carryin: in std_logic_vector(0 downto 0);
  sum: out std_logic_vector(31 downto 0);
  carryout: out std_logic);
end component;
 
signal RegWrite,ALUSrc,MemWrite,MemRead,RegDest,MemToReg,Jump,Zero,Branch,BranchTaken: std_logic;
signal PC_FA_IM,FA_PC_OUT,OUT_IM,FOUR,ALUout,RegOut1,RegOut2,DataWriteIn,MUXaluOut: std_logic_vector(31 downto 0);
signal ALUControl_out: std_logic_vector(3 downto 0);
signal MUXregOut: std_logic_vector(4 downto 0);
signal ALUOp: std_logic_vector(2 downto 0);
signal SignExOut,RAMout,ShiftJump2MuxJump,MuxJump2PC,MuxBranch2MuxJump,ALUbranchout,SignExOutAligned: std_logic_vector(31 downto 0);

begin
  FOUR <= std_logic_vector(to_unsigned(4,32));
  FA_PC1: Adder32 port map(
    in1 => PC_FA_IM,
    in2 => FOUR,
    carryin => "0",
    sum => FA_PC_OUT);
    
  SignExOutAligned <= SignExOut(29 downto 0) & "00";
  Fa_Branch: Adder32 port map(
    in1 => FA_PC_OUT,
    in2 => SignExOutAligned,
    carryin => "0",
    sum => ALUbranchout);
    
  PC1: PC port map(
    inPC => MuxJump2PC,
    outPC => PC_FA_IM,
    clk => clk,
    rst => rst);
    
  IM1: InstructionMemory port map(
    IMin => PC_FA_IM,
    IMout => OUT_IM);
    
  Reg1: RegFile port map(
    RegIn1 => OUT_IM(25 downto 21),
    RegIn2 => OUT_IM(20 downto 16),
    RegWriteIn => MUXregOut,
    DataWriteIn => DataWriteIn,
    RegWrite => RegWrite,
    RegOut1 => RegOut1,
    RegOut2 => RegOut2);
    
  OC1: ControlUnit port map(
    clk => clk,
    OC_in => OUT_IM(31 downto 26),
    RegWrite => RegWrite,
    ALUSrc => ALUSrc,
    ALUOp => ALUOp,
    MemWrite => MemWrite,
    MemRead => MemRead,
    RegDest => RegDest,
    MemToReg => MemToReg,
    Jump => Jump,
    Branch => Branch);
    
  ALUC: ALUControl port map(
    ALUOp => ALUOp,
    Funct => OUT_IM(5 downto 0),
    ALUCont_out => ALUControl_out);
    
  ALU1: ALU port map(
    in1 => RegOut1,
    in2 => MUXaluOut,
    opcode => ALUControl_out,
    ALUout => ALUout,
    Zero => Zero);
    
  RAM: DataMemory port map(
    RAMin => ALUout,
    WriteData => RegOut2,
    MemWrite => MemWrite,
    MemRead => MemRead,
    RAMout => RAMout,
    reset => rst);
    
  Mreg: mux2to1_5 port map(
    Min1 => OUT_IM(20 downto 16),
    Min2 => OUT_IM(15 downto 11),
    Mout => MUXregOut,
    sel => RegDest);
    
  Malu: mux2to1_32 port map(
    Min1 => RegOut2,
    Min2 => SignExOut,
    Mout => MUXaluOut,
    sel => ALUSrc);
  
  Mram: mux2to1_32 port map(
    Min1 => ALUout,
    Min2 => RAMout,
    Mout => DataWriteIn,
    sel => MemToReg);
  
  ShiftJump2MuxJump <= FA_PC_OUT(31 downto 28) & OUT_IM(25 downto 0) & "00";
  Mjump: mux2to1_32 port map(
    Min1 => MuxBranch2Muxjump,
    Min2 => ShiftJump2MuxJump,
    Mout => MuxJump2Pc,
    sel => Jump);
    
  BranchTaken <= Branch and Zero;
  Mbranch: mux2to1_32 port map(
    Min1 => FA_PC_OUT,
    Min2 => ALUbranchOut,
    Mout => MuxBranch2Muxjump,
    sel => BranchTaken);
    
  S_EX: SignExtend port map(
    S_EXin => OUT_Im(15 downto 0),
    S_EXout => SignExOut);
    
  outMIPS <= ALUout;
end structure;

--ALU

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity ALU is port(
  in1,in2: std_logic_vector(31 downto 0);
  opcode: in std_logic_vector(3 downto 0);
  ALUout: out std_logic_vector(31 downto 0);
  Zero: out std_logic);
end ALU;

architecture Behavioral of ALU is

component Adder32 port(
  in1,in2: in std_logic_vector(31 downto 0);
  carryin: in std_logic_vector(0 downto 0);
  sum: out std_logic_vector(31 downto 0);
  carryout: out std_logic);
end component;

component Shifter port(
  Sin: in std_logic_vector(31 downto 0);
  Sout: out std_logic_vector(31 downto 0);
  Sopcode: in std_logic;
  num: in std_logic_vector(4 downto 0));
end component;

signal op_shifter,carryout: std_logic;
signal out_FA,out_SH,slt_result: std_logic_vector(31 downto 0);
signal x: std_logic_vector(31 downto 0) := (others=>'X');

begin
  op_shifter <= '0' when opcode="0111" else '1' when opcode="1000" else 'X';
  FA_ALU: Adder32 port map(
    in1 => in1, 
    in2 => in2, 
    carryin => "0", 
    sum => out_FA,
    carryout => carryout);
  SH_ALU: Shifter port map(
    Sin => in1, 
    Sout => out_SH,
    Sopcode => op_shifter,
    num => in2(4 downto 0));
  slt_result <= std_logic_vector(to_unsigned(0,32)) 
  when (to_integer(signed(in1)) < to_integer(signed(in2))) 
  else std_logic_vector(to_unsigned(1,32));
    
  with opcode select ALUout <=
    out_FA when "0001",
    in1 and in2 when "0010",
    in1 or in2 when "0011",
    in1 nor in2 when "0100",
    in1 and in2 when "0101",
    in1 or in2 when "0110",
    out_SH when "0111",
    out_SH when "1000",
    slt_result when "1100",
    out_Fa when "1101",
    x when others;
    
    Zero <= '1' when ((in1 = in2) and (opcode = "1010")) else '1' when ((in1 /= in2) and (opcode = "1011")) else '0';
end Behavioral;  

--ALUControl 

library ieee;
use ieee.std_logic_1164.all;

entity ALUControl is port(
  ALUOp: in std_logic_vector(2 downto 0);
  Funct: in std_logic_vector(5 downto 0);
  ALUCont_out: out std_logic_vector(3 downto 0));
end ALUControl;

architecture behavioral of ALUControl is
signal tmpALUControl_func,tmpALUControl_op: std_logic_vector(3 downto 0) :=(others=>'0');
begin
with Funct select 
  tmpALUControl_func <=
  "0001" when "100000",
  "0010" when "100100",
  "0011" when "100101",
  "0100" when "100111",
  "0101" when "001100",
  "0110" when "001101",
  "0111" when "000000",
  "1000" when "000010",
  "1100" when "101010",
  "1111" when others;
with ALUOp select
  tmpALUControl_op <=
  "0001" when "001",
  "1010" when "010",
  "1011" when "011",
  "1101" when "100",
  "1111" when others;
with ALUOp select
  ALUCont_out <=
  tmpALUControl_func when "000",
  tmpALUControl_op when others;
end behavioral;

--RegFile

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity RegFile is port(
  RegIn1,RegIn2,RegWriteIn: in std_logic_vector(4 downto 0);
  DatawriteIn: in std_logic_vector(31 downto 0); 
  RegWrite: in std_logic;
  RegOut1,RegOut2: out std_logic_vector(31 downto 0));
end RegFile;

architecture behavioral of RegFile is 
type registers is array (0 to 31) of std_logic_vector(31 downto 0);
signal regs: registers := (others=> (others => '0'));
signal RegWriteDelayed: std_logic;
signal x: std_logic_vector(31 downto 0) := (others=>'X');
begin
  RegOut1 <= regs(to_integer(unsigned(RegIn1)));
  Regout2 <= regs(to_integer(unsigned(RegIn2)));
  RegWriteDelayed <= transport RegWrite after 1 ns;
  regs(to_integer(unsigned(RegWriteIn))) <= DataWriteIn when (RegWriteDelayed='1' and DataWriteIn/=x);
end behavioral;  
    
--Adder32

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity Adder32 is port(
  in1,in2: in std_logic_vector(31 downto 0);
  carryin: in std_logic_vector(0 downto 0);
  sum: out std_logic_vector(31 downto 0);
  carryout: out std_logic);
end Adder32;

architecture behavioral of Adder32 is
signal tmp: std_logic_vector(32 downto 0);
begin 
  tmp <= std_logic_vector(to_signed(to_integer(signed(in1)) +
         to_integer(signed(in2)) + to_integer(signed(carryin)),33));
  carryout <= tmp(32);
  sum <= tmp(31 downto 0);
end behavioral;

--InstructionMemory

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity InstructionMemory is port(
  IMin: in std_logic_vector(31 downto 0);
  IMout: out std_Logic_vector(31 downto 0));
end InstructionMemory;

architecture behavioral of INstructionMemory is
type mem_type is array (0 to 31) of std_logic_vector(31 downto 0);
signal mem: mem_type := (
   "00100000000000000000000000000000",  -- addi $0, $0, 0
   "00100000010000100000000000000000",  -- addi $2, $2, 0
   "00100000010001000000000000000000",  -- addi $2, $4, 0
   "00100000011000000000000000000001",  -- addi $3, $0, 1
   "00100000101000000000000000000011",  -- addi $5, $0, 3
   "00000000011000110011000000100000",  -- L1: add $6, $3, $0
   "10101100100001100000000000000000",  -- sw $6, 0($4)
   "00100000011000110000000000000001",  -- addi $3, $3, 1
   "00100000100001000000000000000001",  -- addi $4, $4, 1
   "00100000101001011111111111111110",  -- addi $5, $5, -1
   "00010100101000001111111111111010",  -- bne $5, $0, L1
   "00000000000000000000000000000000",  -- No Operation
   "00000000000000000000000000000000",  -- NOP
   "00000000000000000000000000000000",  -- NOP
   "00000000000000000000000000000000",  -- NOP
   "00000000000000000000000000000000",  -- NOP
   "00000000000000000000000000000000",  -- NOP
   "00000000000000000000000000000000",  -- NOP
   "00000000000000000000000000000000",  -- NOP
   "00000000000000000000000000000000",  -- NOP
   "00000000000000000000000000000000",  -- NOP
   "00000000000000000000000000000000",  -- NOP
   "00000000000000000000000000000000",  -- NOP
   "00000000000000000000000000000000",  -- NOP
   "00000000000000000000000000000000",  -- NOP
   "00000000000000000000000000000000",  -- NOP
   "00000000000000000000000000000000",  -- NOP
   "00000000000000000000000000000000",  -- NOP
   "00000000000000000000000000000000",  -- NOP
   "00000000000000000000000000000000",  -- NOP
   "00000000000000000000000000000000",  -- NOP
   "00000000000000000000000000000000"  -- NOP
  );
signal FullInstruction: std_logic_vector(31 downto 0);
signal IM_address: integer;
begin
  IM_address <= to_integer(unsigned(IMin)) when (to_integer(unsigned(IMin)) >=0) else 0;
  FullInstruction <= mem(IM_address) when (IM_address >= 0) else std_logic_vector(to_signed(-1,32));
  IMout <= FullInstruction;
end behavioral;

--mux2to1_5

library ieee;
use ieee.std_logic_1164.all;

entity mux2to1_5 is port(
  Min1,Min2: in std_logic_vector(4 downto 0);
  Mout: out std_logic_vector(4 downto 0);
  sel: in std_logic);
end mux2to1_5;

architecture behavioral of mux2to1_5 is
begin
  Mout <= Min1 when sel='0' else Min2 when sel='1';
end behavioral;

--mux2to1_32

library ieee;
use ieee.std_logic_1164.all;

entity mux2to1_32 is port(
  Min1,Min2: in std_logic_vector(31 downto 0);
  Mout: out std_logic_vector(31 downto 0);
  sel: in std_logic);
end mux2to1_32;

architecture behavioral of mux2to1_32 is
begin
  Mout <= Min1 when sel='0' else Min2 when sel='1';
end behavioral;

--ControlUnit

library ieee;
use ieee.std_logic_1164.all;

entity ControlUnit is port(
  clk: in std_logic;
  OC_in: in std_logic_vector(5 downto 0);
  RegWrite: out std_logic;
  ALUSrc: out std_logic;
  ALUOp: out std_logic_vector(2 downto 0);
  MemWrite,MemRead: out std_logic;
  RegDest: out std_logic;
  MemToReg: out std_logic;
  Jump: out std_logic;
  Branch: out std_logic);
end ControlUnit;

architecture behavioral of ControlUnit is
begin
with OC_in select
  RegWrite <= 
  ('1' and clk) when "100011",
  ('1' and clk) when "000000",
  ('1' and clk) when "001000",
  '0' when others;
with OC_in select
  ALUSrc <= 
  '1' after 2 ns when "100011",
  '1' after 2 ns when "101011",
  '1' after 2 ns when "001000",
  '0' when others;
with OC_in select
  ALUOp <=
  "000" after 2 ns when "000000",
  "001" after 2 ns when "100011",
  "001" after 2 ns when "101011",
  "010" after 2 ns when "000100",
  "011" after 2 ns when "000101",
  "100" after 2 ns when "001000",
  "111" when others;
with OC_in select
  MemWrite <= 
  '1' after 10 ns when "101011",
  '0' when others;
with OC_in select
  MemRead <=
  '1' after 2 ns when "100011",
  '0' when others;
with OC_in select
  MemToReg <=
  '1' after 2 ns when "100011",
  '0' when others;
with OC_in select
  RegDest <=
  '0' when "100011",
  '0' when "001000",
  '1' when others;
with OC_in select
  Jump <=
  '1' when "000010",
  '0' when others;
with OC_in select
  Branch <=
  '1' when "000100",
  '1' when "000101",
  '0' when others;
end behavioral;

--PC

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity PC is port(
  inPC: in std_logic_vector(31 downto 0);
  outPC: out std_logic_vector(31 downto 0);
  CLK: in std_logic;
  rst: in std_logic);
  end PC;
architecture behavioral of PC is
begin
  reg: process(CLK)
begin
  if (rst='1') then
    outPC <= std_logic_vector(to_signed(-1,32));
  end if;
  if rising_edge(CLK) then
    outPC <= inPC;
  end if;
end process;
end behavioral;

--DataMemory

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity DataMemory is port(
  RAMin: in std_logic_vector(31 downto 0);
  WriteData: in std_logic_vector(31 downto 0);
  MemWrite: in std_logic;
  MemRead: in std_logic;
  RAMout: out std_logic_vector(31 downto 0);
  reset: in std_logic);
end DataMemory;

architecture behavioral of DataMemory is
type ram_type is array (natural range <>) of std_logic_vector(31 downto 0);
signal ram: ram_type(0 to 15) := (others=> (others=>'0'));
signal Address: integer := 0;
begin
  Address <= to_integer(unsigned(RAMin)) when (to_integer(unsigned(RAMin)) <= 15) else 0;
  ram(Address) <= WriteData when (MemWrite='1' and reset='0');
with reset select
  RAMout <=
  ram(Address) when '0',
  (others=>'0') when others;
end behavioral;

--Shifter

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;    

entity Shifter is port(
  Sin: in std_logic_vector(31 downto 0);
  Sout: out std_logic_vector(31 downto 0);
  Sopcode: in std_logic;
  num: in std_logic_vector(4 downto 0));   
end Shifter;

architecture behavioral of Shifter is
signal tmp: unsigned(31 downto 0);
begin
  tmp <= to_unsigned(to_integer(signed(Sin)),tmp'length) sll
       to_integer(signed(num)) when Sopcode='0' else
       to_unsigned(to_integer(signed(Sin)),tmp'length) srl
       to_integer(signed(num)) when Sopcode='1';      
  Sout <= std_logic_vector(to_signed(to_integer(tmp),Sout'length));
end behavioral;

--SignExtend

library ieee;
use ieee.std_logic_1164.all;

entity SignExtend is port(
  S_EXin: in std_logic_vector(15 downto 0);
  S_EXout: out std_logic_vector(31 downto 0));  
end SignExtend;

architecture behavioral of SignExtend is
signal ones: std_logic_vector(15 downto 0) := (others=>'1');
signal zeros: std_logic_vector(15 downto 0) := (others=>'0');
begin
  S_EXout <= ones & S_EXin when S_EXin(15)='1' else 
           zeros & S_EXin when S_EXin(15)='0';
end behavioral;