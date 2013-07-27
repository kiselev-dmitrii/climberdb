// Выводит все непроданные

SELECT Name, Model, Cost, GROUP_CONCAT(Size, ",") 
FROM Consignment as C JOIN Product as P ON  C.ID = P.ConsignmentID 
WHERE P.IsSold = 0
GROUP BY Name, Model, Cost ORDER BY C.ID 


SELECT C.ID, C.Name, Model, Cost, GROUP_CONCAT(Size, ","), T.Name, C.Gender, C.Comment
FROM  Consignment as C JOIN Product as P ON  C.ID = P.ConsignmentID 
          JOIN Type as T ON C.TypeID = T.ID
WHERE P.IsSold = 0
GROUP BY C.Name, C.Model, C.Cost ORDER BY C.ID 