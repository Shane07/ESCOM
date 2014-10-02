#! /usr/bin/perl

# Por Eder Or - multiaportes.com

sub validarNumero
{
	if($_[0] =~ /^\d+$/)
	{
		return $_[0];
	}
	else
	{
		return 0;
	}
	
}
sub uno
{
	$h = undef;
	for($w = 1; $w <= $_[0]; $w++)
	{
		$h = 1;
		while($h <= $w)
		{
			print "*";
			++$h;
		}
		print "\n";
	}
	print "\n";
}
sub dos
{
	$h = undef;
	for($w = $_[0]; $w >= 1; $w--)
	{
		$h = 1;
		while($h <= $w)
		{
			print "*";
			++$h;
		}
		print "\n";
	}
	print "\n";
}
sub tres
{
	$h = undef;
	$n = undef;
	for($w = 1; $w <= $_[0]; $w++)
	{
		$h = 1;
		$n = $_[0];
		while($h <= $w)
		{
			print " ";
			++$h;
		}
		while($n >= $w)
		{
			print "*";
			--$n;
		}
		print "\n";
	}
	print "\n";
}
sub cuatro
{
	$h = undef;
	$n = undef;
	for($w = $_[0]; $w >= 1; $w--)
	{
		$h = 1;
		$n = $_[0];
		while($h <= $w)
		{
			print " ";
			++$h;
		}
		while($n >= $w)
		{
			print "*";
			--$n;
		}
		print "\n";
	}
	print "\n";
}

print "\nBy stederr[@]multiaportes.com xDD!!\n\n";

if (($ARGV[0] eq '--veces') && (($ARGV[1] ne '') || ($ARGV[1] ne undef)))
{
	$veces = validarNumero($ARGV[1]);
	if($veces == 0)
	{
		print "No metiste un numero\n";
		exit -666;
	}
	uno($veces);
	dos($veces);
	tres($veces);
	cuatro($veces);
	exit 666;
}
else
{
	print "Falta algo, dude...\n";
	exit -666;
}
