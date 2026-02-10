
Module Module1

    Sub Main()

        Dim hostIPAddress As IPAddress = IPAddress.Parse(IpAddressString)

        Dim hostInfo As IPHostEntry = Dns.GetHostByAddress(hostIPAddress) '@violation

    End Sub

End Module