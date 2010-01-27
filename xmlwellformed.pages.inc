<?

function xmlwellformed_show_admin(){	
	
		drupal_set_title(t('Wellformed Nodes Overview'));
	
		$result = db_query('SELECT nid, body FROM {node_revisions} ORDER BY nid ASC');
		while ($node = db_fetch_array($result)){
			$string .= "<a href='/node/".$node["nid"]."/edit'>".$node["nid"]."</a>";
			if(_xml_is_wellformed("<doc>".$node["body"]."</doc>")){
				$string .= " is <span style='color:darkgreen;'>wellformed</span>";
				$wellformed ++;
			}else{
				$string .= " is <span style='color:darkred;'>malformed</span>";
				$malformed ++;
			}
			$string .= "<br/>";
		}
		$page = $wellformed." Nodes are wellformed and ".$malformed." Nodes are malformed<br/>".$string;
		return $page;
}