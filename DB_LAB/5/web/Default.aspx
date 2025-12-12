<%@ Page Title="Home Page" Language="C#" MasterPageFile="~/Site.master" AutoEventWireup="true"
    CodeFile="Default.aspx.cs" Inherits="_Default" %>

<asp:Content ID="HeaderContent" runat="server" ContentPlaceHolderID="HeadContent">
</asp:Content>
<asp:Content ID="BodyContent" runat="server" ContentPlaceHolderID="MainContent">

    <asp:GridView ID="GridView1" runat="server" AutoGenerateColumns="False" 
    DataKeyNames="EmpID" DataSourceID="SqlDataSource1" AllowSorting="True" 
        CellPadding="4" ForeColor="#333333" GridLines="None" Height="195px" 
        Width="355px">
        <AlternatingRowStyle BackColor="White" />
    <Columns>
        <asp:BoundField DataField="EmpID" HeaderText="EmpID" ReadOnly="True" 
            SortExpression="EmpID" />
        <asp:BoundField DataField="EmpName" HeaderText="EmpName" 
            SortExpression="EmpName" />
        <asp:BoundField DataField="Country" HeaderText="Country" 
            SortExpression="Country" />
    </Columns>
        <EditRowStyle BackColor="#7C6F57" />
        <FooterStyle BackColor="#1C5E55" Font-Bold="True" ForeColor="White" />
        <HeaderStyle BackColor="#1C5E55" Font-Bold="True" ForeColor="White" />
        <PagerStyle BackColor="#666666" ForeColor="White" HorizontalAlign="Center" />
        <RowStyle BackColor="#E3EAEB" />
        <SelectedRowStyle BackColor="#C5BBAF" Font-Bold="True" ForeColor="#333333" />
        <SortedAscendingCellStyle BackColor="#F8FAFA" />
        <SortedAscendingHeaderStyle BackColor="#246B61" />
        <SortedDescendingCellStyle BackColor="#D4DFE1" />
        <SortedDescendingHeaderStyle BackColor="#15524A" />
</asp:GridView>
<asp:SqlDataSource ID="SqlDataSource1" runat="server" 
    ConnectionString="<%$ ConnectionStrings:Johir_PetCareConnectionString %>" 
    SelectCommand="SELECT * FROM [Employee]"></asp:SqlDataSource>

</asp:Content>
