difference()
{
    union()
    {
        cylinder(r=40,h=80);
        translate([0,0,79])sphere(r=39);
    }
translate([0,0,1])cylinder(r=39,h=70);
    
translate([0,0,79])sphere(r=38);
translate([0,0,70])cylinder(r1=39,r2=38,h=9);
translate([-40,-40,85])cube([80,80,80]);
    
translate([0,40,70])rotate([90,0,0])cylinder(r=5,h=80);

translate([-5,-50,60])cube([10,100,3]);
    
}