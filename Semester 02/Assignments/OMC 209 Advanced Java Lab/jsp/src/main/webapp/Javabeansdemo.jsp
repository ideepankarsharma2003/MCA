<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>JSP Page</title>
</head>
<body>
<h2>Populating Beans and displaying data through JSP</h2>
<jsp:useBean id="myid" class="com.example.Practical_12_JavaBeans" scope="request">
  <jsp:setProperty name="myid" property="studName"/>
  <jsp:setProperty name="myid" property="age"/>
</jsp:useBean>
<p><h2>Student Name: <jsp:getProperty name="myid" property="studName"/></h2></p>
<p><h2>Student Age: <jsp:getProperty name="myid" property="age"/></h2></p>
</body>
</html>
