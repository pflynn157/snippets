with Ada.Text_IO; use Ada.Text_IO;

procedure Main is

    type ObjType is (None, Add, Sub, Mul, Div, Int, Id);
    
    type Obj;
    type ObjPtr is access Obj;
    type Obj is record
        obj_type : ObjType;
        value : integer := 0;
        lval, rval : ObjPtr;
    end record;
    
    -- Test
    int1 : ObjPtr := new Obj'(Int, 20, null, null);
    int2 : ObjPtr := new Obj'(obj_type => Int, value => 30, others => <>);
    op : Obj := (obj_type => Add, lval => int1, rval => int2, others => <>);
    
    procedure Print(item : Obj; indent : integer);
    procedure Print(item : ObjPtr; indent : integer) is
        item2 : Obj := item.all;
    begin
        Print(item2, indent);
    end Print;
    
    procedure Print(item : Obj; indent : integer) is
        use_parens : boolean := false;
    begin
        for i in 0 .. indent loop Put(" "); end loop;
        --Put(ObjType'Image(item.obj_type) & " " & Integer'Image(item.value) & " ");
        Put(ObjType'Image(item.obj_type) & " ");
        if item.obj_type = Add or item.obj_type = Sub or item.obj_type = Mul or item.obj_type = Div then
            use_parens := true;
        end if;
        if use_parens then Put("("); end if;
        if item.obj_type = Int then
            Put(Integer'Image(item.value));
        end if;
        if item.lval /= null then
            Print(item.lval, indent);
        end if;
        if item.rval /= null then
            Put("), (");
            Print(item.rval, indent);
        end if;
        if use_parens then Put(")"); end if;
    end Print;

begin
    Put_Line("Hello!");
    New_Line;
    Print(op, 2);
    New_Line;
end Main;

