ifconfig | grep "\bether\b" | sed "s/ether //g" | tr -d '\t' | tr -d ' '
